//This is required to use the module
const pg = require('pg');

process.env.PGDATABASE = 'pg';

// Create a pool of connections to allow multiple users
const pool = new pg.Pool();

pool.on('error', (err, client) => {
        console.log(err.stack);
        process.exit(-1);
});

pool.connect((err, client, done) => {
        if (err) throw err;
        createGame(client, done);
});

//create table games that we will populate with data
function createGame(client, done) {
        const q = ' create table game (        ' +
                  ' name char(255) primary key,   ' +
                  ' score integer                  ' +
                  ')                            ';
        client.query(q, (err) => {
                if (err) throw err; else insertA(client, done);
        });
}

//This function will select all of the data in the table
function selectAll(client, cb) {
        client.query("select * from game order by name", (err, result) => {
                if (err) throw err;
                result.rows.map((row, i) => {
                        console.log(' ' + i + " " + row.name + ' ' + row.score);
                });
                cb();
        });
}

//This function will insert a row
function insertRow(client, name, score, cb) {
        client.query("insert into game values ($1::text, $2)",[name, score], (err) => {
                if (err) throw err; else cb();
        });
}

//inserts the first bit of data going from A - D
function insertA(client, done) {
        insertRow(client, 'Fallout', 8, () => {
                insertB(client, done);
        });
}

function insertB(client, done) {
        insertRow(client, 'Overwatch', 9, () => {
                insertC(client, done);
        });
}

function insertC(client, done) {
        insertRow(client, 'PUBG', 7, () => {
                insertD(client, done);
        });
}

function insertD(client, done) {
        insertRow(client, 'Siege', 8, () => {
                updateSiege(client, done);
        });
}

//Function to update a score
function updateRow(client, name, score, cb) {
        client.query("update game set score = $1 where name = $2::text", [score, name], (err) => {
                if (err) throw err;
                cb();
        });
}

// Deletes the video game 'Siege'
function selectAll1(client, done) {
        selectAll(client, () => {
                deleteSiege(client, done);
        });
}

//Ends the connection to the pool that will then give another user the oportunity to connect if they were waiting
function myEnd(client, done) {
        done();
        pool.end();
}

// Defines the update siege function
function updateSiege(client, done) {
        updateRow(client, 'Siege', 10, () => {
                selectAll1(client, done);
        });
}

//deletes a row
function deleteRow(client, name, cb) {
        client.query("delete from game where name = $1::text", [name], (err) => {
                if (err) throw err;
                cb();
        });
}

function selectAll2(client, done) {
        selectAll(client, () => {
                myEnd(client, done);
        });
}

//defines the delete siege function
function deleteSiege(client, done) {
        deleteRow(client, 'Siege', () => {
                selectAll2(client, done);
        });
}
