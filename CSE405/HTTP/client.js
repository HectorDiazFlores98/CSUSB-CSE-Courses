//required to access the net module
const net = require('net');

/*
 * creates a client tcp socket
 * Does not connnect right away but after function has returned
 * it is connecting to local host on port 8000. That is the port our server.js is running on.
 */
const socket = net.createConnection({
  host: 'localhost',
  port: 8000
});

/*
 * Because the connections arent made until after the function returns, 
 * we need to register even handlers with the const socket to moniter any changes
 * first thing that should be checked is if a connection was made at all 
 * also if both server and client are ready to receive/send packets. 
 * In HTTP the client sends first message confirming connection called the 'HTTP Request Message', 
 * the code below shows how to send that message.
*/
socket.on('connect', () => {
  const req =
    'GET / HTTP/1.1  \r\n' +
    'Host: localhost \r\n' +
    '\r\n';
  socket.end(req);  // Send req string and then close this side of the TCP socket.
});

/*
 * we close the socket as we only wanted to let the server know we connected. 
 * After we open the socket again and store any sort of data the socket may emit in a 'data' event. 
 * It may happen several times in a single connection so we will use the callback parameter 'chunk' as in 'chunks of data' *  because the data emited is raw, we need to process it to a string with the char standard 'utf8' to make it readable
*/
socket.on('data', (chunk) => {
  console.log(chunk.toString('utf8'));
});
