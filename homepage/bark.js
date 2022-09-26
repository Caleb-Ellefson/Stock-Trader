function bark() {
 var image = document.getElementById("changeimg");
 if (image.scr.match("/Kora/Sitting.png")) {
    image.src = "/Kora/barking-removebg-preview.png";
 }
 else {
    image.src = "/Kora/Sitting.png";
 }

}