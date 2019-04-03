const player = require('play-sound')();
var StepSequencer = require('step-sequencer');

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

    console.log("KICK")
    // console.log(step);
})
    .on('1', function (step) {
        console.log(step);
    })
    .on('2', function (step) {
        console.log(step);
    })
    .on('3', function (step) {
        console.log(step);
    })
    .on('4', function (step) {

        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });

        console.log("KICK")
        // console.log(step);
    })
    .on('5', function (step) {
        console.log(step);
    })
    .on('6', function (step) {
        console.log(step);
    })
    .on('7', function (step) {
        console.log(step);
    });

stepSequencer_0.play();

// The StepSequencer emits the number of
// the step when that step is to be played
stepSequencer_1.on('0', function (step) {
    console.log(step);
})
    .on('1', function (step) {
        console.log(step);
    })
    .on('2', function (step) {
        console.log(step);
    })
    .on('3', function (step) {

        // player.play('./Crash.wav', (err) => {
        //     if (err) console.log(`Could not play sound: ${err}`);
        // });

        // console.log("Crash")
        // console.log(step);
    })
    .on('4', function (step) {
        console.log(step);
    })
    .on('5', function (step) {
        console.log(step);
    })
    .on('6', function (step) {
        console.log(step);
    })
    .on('7', function (step) {
        // player.play('./Crash.wav', (err) => {
        //     if (err) console.log(`Could not play sound: ${err}`);
        // });

        // console.log("Crash")
        // console.log(step);
    });

stepSequencer_1.play();

// The StepSequencer emits the number of
// the step when that step is to be played
stepSequencer_2.on('0', function (step) {
    console.log(step);
})
    .on('1', function (step) {
        console.log(step);
    })
    .on('2', function (step) {
        console.log(step);
    })
    .on('3', function (step) {
        console.log(step);
    })
    .on('4', function (step) {
        console.log(step);
    })
    .on('5', function (step) {

        player.play('sounds/Boing.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });

        console.log("Boing")
        // console.log(step);
    })
    .on('6', function (step) {
        console.log(step);
    })
    .on('7', function (step) {
        console.log(step);
    });

stepSequencer_2.play();

// The StepSequencer emits the number of
// the step when that step is to be played
stepSequencer_3.on('0', function (step) {
    console.log(step);
})
    .on('1', function (step) {
        console.log(step);
    })
    .on('2', function (step) {
        console.log(step);
    })
    .on('3', function (step) {
        console.log(step);
    })
    .on('4', function (step) {
        console.log(step);
    })
    .on('5', function (step) {
        console.log(step);
    })
    .on('6', function (step) {
        console.log(step);
    })
    .on('7', function (step) {
        console.log(step);
    });

stepSequencer_3.play();
