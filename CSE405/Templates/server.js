const http     = require('http');
const qs       = require('querystring');
const sessions = require('./sessions');
const st       = require('st');
const fs       = require('fs');

const mount = st({
       path: 'views/'
});

const homeTemplate = fs.readFileSync('views/home.html', 'utf8');
const colorTemplate = fs.readFileSync('views/color.html', 'utf8');
const loginTemplate = fs.readFileSync('views/login.html', 'utf8');

const server = http.createServer();

server.listen(8000);
server.on('request', (req, res) => {
    sessions.filter(req, res);
    if (req.url === '/login.html') {
        handleLoginPage(req, res);
      } else if (req.url === '/login') {
          handleLoginForm(req, res);
      } else if (!req.session.hasOwnProperty('username')) {
          redirectLoginPage(res);
      } else if (req.url === '/color') {
          handleColorForm(req, res);
      } else if (req.url === '/color.html') {
          handleColorPage(req, res);
      } else if (req.url === '/') {
          handleHomePage(req, res);
      } else if (req.url === '/logout') {
          delete req.session.username;
          redirectLoginPage(res);
      } else {
          mount(req, res);
      }
 });

 function handleHomePage(req, res) {
    res.setHeader('Content-type', 'text/html');
    const html = homeTemplate.replace('#color#', req.session.color);
    res.end(html);
  }
  
  function handleColorPage(req, res) {
    var html;
    switch (req.session.color) {
      case 'FF0000':
        html = colorTemplate.replace('#red#'   , 'checked');
        html = html         .replace('#green#' , '       ');
        html = html         .replace('#blue#'  , '       ');
        break;
      case '00FF00':
        html = colorTemplate.replace('#red#'   , '       ');
        html = html         .replace('#green#' , 'checked');
        html = html         .replace('#blue#'  , '       ');
        break;
      case '0000FF':
        html = colorTemplate.replace('#red#'   , '       ');
        html = html         .replace('#green#' , '       ');
        html = html         .replace('#blue#'  , 'checked');
        break;
      default:
        html = colorTemplate.replace('#red#'   , '       ');
        html = html         .replace('#green#' , '       ');
        html = html         .replace('#blue#'  , '       ');
        break;
    }
    res.setHeader('Content-type', 'text/html');
    res.end(html);
  }
  
  function handleLoginPage(req, res) {
    var html = loginTemplate;
  
    if (req.session.error === true) { 
    html = loginTemplate.replace('hidden'   , '__');
    }
  
    res.setHeader('Content-type', 'text/html');
    res.end(html);
  }
  
  function handleLoginForm(req, res) {
    let body = '';
    req.on('data', (chunk) => {
      body += chunk;
    });
    req.on('end', () => {
      const form = qs.parse(body);
      if (form.username !== 'fred' || form.password !== '1234') {
        req.session.error = true
        redirectLoginPage(res);
  
      }else{
  
        req.session.username = form.username;
        redirectHomePage(res);
      }
    });
  }
  
  
  
  function redirectHomePage(res) {
    res.statusCode = 301;
    res.setHeader('Location', '/');
    res.end();
  }
  
  function redirectLoginPage(res) {
    res.statusCode = 301;
    res.setHeader('Location', '/login.html');
    res.end();
  }
  
  function handleColorForm(req, res) {
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
      res.writeHead(302, { 'Location': '/' });
      res.end();
    });
  }
  