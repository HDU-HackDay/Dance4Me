const dgram = require('dgram');
const server = dgram.createSocket('udp4');

const JSONB = require('json-buffer')

const PORT = 9000;
const HOST = '192.168.1.255';

server.on('listening', function () {
    const address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});

server.on('message', function (message, remote) {
    // console.log(remote.address + ':' + remote.port + ' - ' + message);
    const type1 = message.readInt8(1);
    const type2 = message.readInt8(2);
    const module_id = message.readInt32BE(3);
    const distance = message.readFloatBE(7);
    const breath = message.readFloatBE(11);
    const heartbeat = message.readFloatBE(15);
    const visibility = message.readFloatBE(19);
    const result = message.readInt32BE(23);
    
    console.log({
        type1,
        type2,
        module_id,
        distance,
        breath,
        heartbeat,
        visibility,
        result
    });
});

server.on('error', (err) => {
    console.log(`server error:\n${err.stack}`);
    server.close();
});

server.bind(PORT, HOST);