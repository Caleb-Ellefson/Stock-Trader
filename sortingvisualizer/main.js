
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

function swap(ele1, ele2)
{
    let temp=ele1.style.height;
    ele1.style.height=ele2.style.height;
    ele2.style.height=temp;
}

function delay(milisec) {
    return new Promise(resolve => {
        setTimeout(() => { resolve('') }, milisec);
    })
}

function disableSortingBtn(){
    document.querySelector("#bubble").disabled = true;
    document.querySelector("#insertion").disabled = true;
    document.querySelector("#merge").disabled = true;
    document.querySelector("#quick").disabled = true;
    document.querySelector("#selection").disabled = true;
}

function enableSortingBtn(){
    document.querySelector("#bubble").disabled = false;
    document.querySelector("#insertion").disabled = false;
    document.querySelector("#merge").disabled = false;
    document.querySelector("#quick").disabled = false;
    document.querySelector("#selection").disabled = false;
}

function disableSizeSlider(){
    document.getElementById("sizer").disabled = true;
}

function enableSizeSlider(){
    document.getElementById("sizer").disabled = false;
}


function bubble (){

    const ele=document.querySelectorAll(".sort");
    
    for (let i=0; i<ele.length-1; i++)
    {
        for (j=0; j<ele.length-1-i; j++)
        {
            ele[j].style.background='red';
            ele[j+1].style.background='red';

            if(parseInt(ele[j].style.height) > parseInt(ele[j+1].style.height))
            {
                await delay(time);
                swap(ele[j], ele[j+1]);
            }

            ele[ele.length-i-1].style.background='green';

        }
        ele[0].style.background='green';
    }
    document.getElementById('bubble').addEventListener("click", async function(){
        disableSizeSlider();
        disableSortingBtn();
        bubble();
        enableSizeSlider();
        enableSortingBtn();
    });
}
