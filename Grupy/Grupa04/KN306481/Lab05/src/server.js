var net = require('net');
var HOST = 'app_server';
var PORT = 8081;

net.createServer(function(sock) {

    console.log('POLACZONO Z: ' + sock.remoteAddress +':'+ sock.remotePort);
    
    sock.on('data', function(data) {
        console.log('DATA ' + sock.remoteAddress + ': ' + data);
        sock.write('ODCZYT DANYCH:     \n\n "' + data + '"\n\n');

    });

    sock.on('close', function(data) {
        console.log('ZAKONCZONO: ' + sock.remoteAddress +' '+ sock.remotePort);
    });

}).listen(PORT, HOST);

console.log('SERWER NASŁUCHUJE NA PORCIE: ' + HOST +':'+ PORT);
