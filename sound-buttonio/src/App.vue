/***
 * Adrian Verdugo ( アドリアン　)
 * @github adrian273
 * @since 11/4/2020
 * 
 */
 
<template>
  <v-app>
    <v-app-bar app color="primary" dark>
      <div class="d-flex align-center"></div>
      <v-spacer></v-spacer>
    </v-app-bar>

    <v-main style="padding: 150px">
      <h1>Sonido 1</h1>
      <audio controls id="sound1" style="" autoplay>
        <source src="./assets/sounds/organo1.mp3" type="audio/mpeg" />
        Your browser does not support the audio element.
      </audio>
      <h1>Sonido 2</h1>
      <audio controls id="sound2" style="" autoplay>
        <source src="./assets/sounds/organo2.mp3" type="audio/mpeg" />
        Your browser does not support the audio element.
      </audio>
      <h1>Sonido 3</h1>
      <audio controls id="sound3" style="" autoplay>
        <source src="./assets/sounds/organo3.mp3" type="audio/mpeg" />
        Your browser does not support the audio element.
      </audio>
      <h1>Sonido 4</h1>
      <audio controls id="sound4" style="" autoplay>
        <source src="./assets/sounds/organo4.mp3" type="audio/mpeg" />
        Your browser does not support the audio element.
      </audio>
    </v-main>
  </v-app>
</template>

<script>
import io from "socket.io-client";
var socket = io.connect("http://localhost:4000");

export default {
  name: "App",
  data: () => ({
    //
  }),
  mounted() {
    socket.on("play", (response) => {
      console.log(response);
      if (response == "1") {
        var sound1 = document.getElementById("sound1").play();
        if (sound1 !== undefined) {
          sound1.then((_) => {}).catch((error) => {});
        }
      } else if (response == "2") {
        var sound2 = document.getElementById("sound2").play();
        if (sound2 !== undefined) {
          sound2.then((_) => {}).catch((error) => {});
        }
      } else if (response == "3") {
        var sound3 = document.getElementById("sound3").play();
        if (sound3 !== undefined) {
          sound3.then((_) => {}).catch((error) => {});
        }
      } else if (response == "4") {
        var sound4 = document.getElementById("sound4").play();
        if (sound4 !== undefined) {
          sound2.then((_) => {}).catch((error) => {});
        }
      }
    });
  },
  methods: {
    autoplay() {},
  },
};
</script>
