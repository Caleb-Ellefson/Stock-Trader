
// Finding Size of Array
let arrsize=document.querySelector('#sizer');
arrsizer.addEventListener('input', function(){
    generatebars(parseInt(arrsizer.value))});
generatebars();

// Finding Sorting Speed
let time=100;
let sortspeed=document.quertSelector('#speed');
sortspeed.addEventListener('input', function(){
    time=245-parseInt(sortspeed.value);
})


// Generate bars
function generatebars(noBar=60){
    document.getElementById("bar").innerHTML='';
    let bars=[];
    for(let i=0; i<noBar; i++)
    {
        bar.push()
    }
}