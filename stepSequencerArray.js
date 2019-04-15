// Een POC die test of je een array kan runnen die de geluidjes afspeelt.

const player = require('play-sound')();
var StepSequencer = require('step-sequencer');


var tempo = 60;
var division = 8;
var sequence_arduino = [0,1,0,0,0,0,0,1];
var stepSequencer_arduino = new StepSequencer(tempo, division, sequence_arduino);

// listen for the "keypress" event
// process.stdin.on('keypress', function (ch, key) {
//     if (key.name == 'p') 
//     { 
//         player.play('/sounds/kick.wav', (err) => {
//             if (err) console.log(`Could not play sound: ${err}`);
//         });
//     }
//   });
//   process.stdin.setRawMode(true);

for(var i=0; i++;i <sequence_arduino.length){
    if(i==1){
        console.log('Kick');
        player.play('sounds/kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    };
};

stepSequencer_arduino.play();

// stepSequencer_0.on('0', function (step) {

//     player.play('sounds/kick.wav', (err) => {
//         if (err) console.log(`Could not play sound: ${err}`);
//     });

//     console.log("KICK")
//     // console.log(step);
// })
//     .on('1', function (step) {
//         console.log(step);
//     })
//     .on('2', function (step) {
//         console.log(step);
//     })
//     .on('3', function (step) {
//         console.log(step);
//     })
//     .on('4', function (step) {

//         player.play('sounds/kick.wav', (err) => {
//             if (err) console.log(`Could not play sound: ${err}`);
//         });

//         console.log("KICK")
//         // console.log(step);
//     })
//     .on('5', function (step) {
//         console.log(step);
//     })
//     .on('6', function (step) {
//         console.log(step);
//     })
//     .on('7', function (step) {
//         console.log(step);
//     });

// stepSequencer_0.play();