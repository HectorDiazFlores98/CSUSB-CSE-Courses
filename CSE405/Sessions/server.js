const http     = require('http');
const qs       = require('querystring');
//Use the sessions js file we created
const sessions = require('./sessions');

const server = http.createServer();

server.listen(8000);

server.on('request', (req, res) => {
        sessions.filter(req, res);
        if (req.url === '/color') {
                handleColor(req, res);
        }else if (req.url === '/') {
                res.setHeader('Content-type', 'text/html');
/* The res.end will respond with html code with various color choices that will stay with the user during the remainder of their session*/
		res.end(
                    '<p style="color: #' + req.session.color + '">Hello</p>' +
                    '<form action="/color" method="post" enctype="x-www-form-urlencode">' +
                    '<input type="radio" name="color" value="FF0000" /> Red   <br>'       +
                    '<input type="radio" name="color" value="00FF00" /> Green <br>'       +
                    '<input type="radio" name="color" value="0000FF" /> Blue  <br>'       +
                    '<input type="submit" value="Submit" />'                              +
                    '</form>'
                );
        }else {
            res.writeHead(404);
            res.end('Not found');
        }
});

function handleColor(req, res) {
        let body = '';
        req.on('data', (chunk) => {
                body += chunk;
        });
        req.on('end', () => {
                const form = qs.parse(body);
		if (
                    form.color !== 'FF0000' &&
                    form.color !== '00FF00' &&
                    form.color !== '0000FF'
                ) {
                    res.writeHead(400);
                    res.end('Bad request');
                }
                req.session.color = form.color;
                //http code 302 is a redirection code 
		res.writeHead(302, { 'Location': '/' });
                res.end();
        });
}
