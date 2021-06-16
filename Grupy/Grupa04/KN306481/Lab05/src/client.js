var net = require('net');
var HOST = 'app_server';
var PORT = 8081;

var client = new net.Socket();
client.connect(PORT, HOST, function() {

    console.log('POLACZONO Z HOSTEM ' + HOST + ':' + PORT);
    console.log('KOMUNIKAT: ');
    client.write('\n\n WYSYŁAM DANE DO SERVERA! \n\n');

});

client.on('data', function(data) {

    console.log('DANE: ' + data);
    client.destroy();

});

client.on('close', function() {
    console.log('POŁĄCZENIE ZAKONCZONE.');
});
