const path = require('path');
const fs = require('fs');
const solc = require('solc');

// get path to .sol source and read file contents into source var
const inboxPath = path.resolve(__dirname, 'contracts', 'Inbox.sol');
const source = fs.readFileSync(inboxPath, 'utf-8');

// compile from source
module.exports = solc.compile(source, 1).contracts[':Inbox'];