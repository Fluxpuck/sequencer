const player = require('play-sound')();
var StepSequencer = require('step-sequencer');
var keypress = require('keypress');

// Instantiate a new StepSequencer object
var tempo = 60;
var division = 8;
var sequence_0 = [0, 1, 2, 3, 4, 5, 6, 7];
var sequence_1 = [0, 1, 2, 3, 4, 5, 6, 7];
var sequence_2 = [0, 1, 2, 3, 4, 5, 6, 7];
var sequence_3 = [0, 1, 2, 3, 4, 5, 6, 7];
var stepSequencer_0 = new StepSequencer(tempo, division, sequence_0);
var stepSequencer_1 = new StepSequencer(tempo, division, sequence_1);
var stepSequencer_2 = new StepSequencer(tempo, division, sequence_2);
var stepSequencer_3 = new StepSequencer(tempo, division, sequence_3);

// The StepSequencer emits the number of
// the step when that step is to be played
stepSequencer_0.on('0', function (step) {

    player.play('sounds/kick.wav', (err) => {
        if (err) console.log(`Could not play sound: ${err}`);
    });
})
    .on('1', function (step) {
        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });    
    })
    .on('2', function (step) {
        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });    
    })
    .on('3', function (step) {
        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });    
    })
    .on('4', function (step) {
        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('5', function (step) {
        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });    
    })
    .on('6', function (step) {
        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });    
    })
    .on('7', function (step) {
        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });    
    });

stepSequencer_0.play();


stepSequencer_1.on('0', function (step) {
    player.play('sounds/Crash.wav', (err) => {
        if (err) console.log(`Could not play sound: ${err}`);
    });
})
    .on('1', function (step) {
        player.play('sounds/Crash.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('2', function (step) {
        player.play('sounds/Crash.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('3', function (step) {
        player.play('sounds/Crash.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('4', function (step) {
        player.play('sounds/Crash.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('5', function (step) {
        player.play('sounds/Crash.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('6', function (step) {
        player.play('sounds/Crash.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('7', function (step) {
        player.play('sounds/Crash.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })

stepSequencer_1.play();


stepSequencer_2.on('0', function (step) {
        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('1', function (step) {
        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('2', function (step) {
        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('3', function (step) {
        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('4', function (step) {
        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('5', function (step) {
        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('6', function (step) {
        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
    .on('7', function (step) {
        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    })
stepSequencer_2.play();

