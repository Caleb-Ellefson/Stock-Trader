import React from 'react';
import memesData from "../memesData.js";

function generate(){
    let num = Math.floor(Math.random() * 100);
    data[num[]]
}


export default function Meme () {
    return(
        <main className="meme">
            <div className="form">
                <input className="meme--input" type="text" placeholder="Top text" />
                <input className="meme--input" type="text" placeholder="Bottom text" />
                <button  className="meme--button"> Get a new meme image 🖼️</button>
            </div>
        </main>
    )
}