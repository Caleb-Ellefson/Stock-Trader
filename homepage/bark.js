function bark() {
 var image = document.querySelector('#changeimg');
 image.onclick = function() {
    image.src = "/Kora/barking-removebg-preview.png";
    changetext();
};
}

function changetext() {
    var x = document.getElementById("intro_subheader");
    if (x.innerHTML === "Kora doesn't like to be touched.") {
      x.innerHTML = "Now, why would you do that?";
    } else {
      x.innerHTML = "Kora doesn't like to be touched.";
    }
  }