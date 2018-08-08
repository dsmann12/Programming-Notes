const assert = require('assert');
const ganache = require('ganache-cli');
const Web3 = require('web3');

// const web3 = new Web3(ganache.provider());
// const { interface, bytecode } = require('../compile');

// update web3 code because broken packages
const provider = ganache.provider();
const web3 = new Web3(provider);

const { interface, bytecode } = require('../compile');

let accounts;
let inbox;
const INITIAL_MESSAGE = "Hi there!";

beforeEach(async () => {
    // Get a list of all accounts
    // returns a promise 
    accounts = await web3.eth.getAccounts();
    // Use one of those acounts to deploy the contract
    inbox = await new web3.eth.Contract(JSON.parse(interface))
    .deploy({ data: bytecode, arguments: [INITIAL_MESSAGE] })
    .send({ from: accounts[0], gas: '1000000' });

    // Added code because web3 broken packages
    inbox.setProvider(provider);
});

describe('Inbox', () => {
    it('deploys a contract', () => {
        // checks that whatever is passed in exists
        assert.ok(inbox.options.address); 
    });

    it('has a default message', async () => {
        const message = await inbox.methods.message().call();
        assert.equal(message, INITIAL_MESSAGE);
    });

    it('can change the message', async () => {
        await inbox.methods.setMessage('bye there!').send({ 
            from: accounts[0],
        });
        const message = await inbox.methods.message().call();
        assert.equal(message, 'bye there!');
    });
});