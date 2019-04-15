// Een POC die test of je een array kan runnen die de geluidjes afspeelt.

const player = require('play-sound')();
var StepSequencer = require('step-sequencer');


var tempo = 60;
var division = 8;
var sequence_arduino = [0,1,2,3,4,5,6,7];
var stepSequencer_arduino = new StepSequencer(tempo, division, sequence_arduino);

// for(var i=0; i++;i <sequence_arduino.length){
//     if(i==1){
//         console.log('Kick');
//         player.play('sounds/kick.wav', (err) => {
//             if (err) console.log(`Could not play sound: ${err}`);
//         });
//     };
// };

// stepSequencer_arduino.play();

    stepSequencer_arduino.on('0', function (step) {

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
    })
    

stepSequencer_arduino.play();
