
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
        bar.push(Math.floor(Math.random()*400)+1);
    }
}

const divs=document.querySelector('#bar');

for(let x=0; x<noBar; x++)
    {
        const temp=document.createElement("div");
        temp.classList.add('sort');
        temp.classList.add('Baritem');
        temp.style.height=bars[x]+"px";
        divs.append(temp);
    }

document.getElementById("newarr").addEventListener("click",function(){
    generateBars(arrsizer.value);
    enableSortingBtn();
    enableSizeSlider();
});
