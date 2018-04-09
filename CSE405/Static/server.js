const http = require('http');
const st = require('st');

const port = 8000;

var mount = st({
  path: 'public/',
  index: 'index.html'
});

const server = http.createServer((req, res) => {

/* if the requested url ends in /hi, serve the following content*/  
if (req.url === '/hi') 
    {
	res.end("<div>You requested /hi.</div>")
    }	
	/*or else, serve the usual index file*/
	else mount(req, res);
});

server.listen(port, () => {
        console.log(`Server running at http://localhost:${port}/`);
});
