const http = require('http');
const st = require('st');
const qs = require('querystring');

const port = 8000;

var mount = st({
  path: 'public/',
  index: 'index.html'
});

const server = http.createServer((req, res) => {

/* if the requested url ends in /hi, serve the following content*/  
if (req.url === '/test') 
    {
	handleFormTest(req, res);
	console.log("Order Received!");
    } else {
	 mount(req, res);
	}
});

server.listen(port, () => {
        console.log(`Server running at http://localhost:${port}/`);
});

function handleFormTest(req, res) {
  console.log('\nForm data received:\n');
  console.log(req.headers);
  console.log('\n');
  let body = '';
  req.on('data', (chunk) => {
    body += chunk;
  });
  req.on('end', () => {
    const form = qs.parse(body);
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/html');
    res.end('<h1>Order For: </h1>\n' + form.firstname + ' ' + form.lastname + '\n' + '<p>Flavors: ' + form.flavor + '</p>\n' + '<p>Topping: ' + form.topping + '</p>\n');
    console.log(form);
  });
}

