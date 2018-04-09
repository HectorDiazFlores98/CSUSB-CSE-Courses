/*this will create a table called test*/
create table test (
        id varchar(255) primary key,
        x integer
);

/* this deletes the test table*/
drop table test;

/* this will create a table called movieRatings*/
create table movieRatings(
	id varchar(255) primary key,
	x integer
);

/* insert various movies into the table */
insert into movieRatings values ('Star Wars', 10);
insert into movieRatings values ('Pulp Fiction', 10);
insert into movieRatings values ('The Godfather', 10);

/* display the table */
select * from movieRatings;

/* display by id*/
select * from movieRatings where id='Pulp Fiction';

/* update movies scores*/
update movieRatings set x = 9 where id='The Godfather';

select * from movieRatings;

/* delete a movie from table*/
delete from movieRatings where id='Pulp Fiction';

select * from movieRatings;
