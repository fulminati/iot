/*
 File: iot.js
 <write description here>

 ArduinoDK
 https://git.io/fAF8y
 */

const sandbox = require('arduinodk-sandbox')
    , yoctojs = require('yoctojs')
    , server = sandbox.createServer()
    , header = sandbox.readFile(__dirname + '/page/header.html')
    , footer = sandbox.readFile(__dirname + '/page/footer.html')

server.on('/', () => {
    server.send(200, 'text/html', header + sandbox.readFile(__dirname + '/page/index.html') + footer);
})

server.on('/settings', () => {
    server.send(200, 'text/html', header + sandbox.readFile(__dirname + '/page/settings.html') + footer);
})

server.on('/api', () => {
    server.send(200, 'text/plain', 'Hello World!');
})

server.on('/iot.js', () => {
    server.send(200, 'application/javascript', yoctojs(__dirname + '/iot.js'));
})

server.on('/iot.css', () => {
    server.send(200, 'text/css', sandbox.readFile(__dirname + '/iot.css'));
})
