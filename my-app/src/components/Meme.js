import React from 'react';
import memesData from "../memesData.js";

function generate(){
    const memeArray = memesData.data.memes
    const num = Math.floor(Math.random() * memesArray.length);
    last_num = num

    const url = memeArray[randomNumber].url
}


export default function Meme () {
    return(
        <main className="meme">
            <div className="form">
                <input className="meme--input" type="text" placeholder="Top text" />
                <input className="meme--input" type="text" placeholder="Bottom text" />

                <button
                onClick={generate}
                className="meme--button">
                Get a new meme image 🖼️
                </button>

            </div>
        </main>
    )
}