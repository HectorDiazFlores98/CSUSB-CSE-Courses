/*
 * Like the 'net' module, we need to declare const http connection 
 */
const http = require('http');
/* 
 * This message was given to us by Prof. Turner
 * We must have the server display the message and a client receive it
 */
const html =
  "<html>"                           +
  "<head><title>405</title></head>"  +
  "<body><h1>hi</h1></body>"         +
  "</html>";

/* create the server and give it a request and response */
const server = http.createServer((req, res) => {
/*let the response know to expect html code */
res.setHeader('Content-Type', 'text/html');
res.end(html);
});

/* listen on port 8000 */
server.listen(8000,() => {
console.log('Open the following URL in browser:');
console.log('http://localhost:8000/');
console.log('');
});

/* On a connection let the server know something connected to it and display the * message from client */

server.on('connection', (socket) => {
  console.log('Something connected to me.');
  socket.on('data', (data) => {
    console.log('Received from client:\n' + data);
    socket.end(); // Send response and close connection.
  });
});

