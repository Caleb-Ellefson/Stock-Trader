import React from 'react';
import memesData from "../memesData.js";





export default function Meme () {
    const [isImportant, current_meme] = React.useState("Image")

    function generate(){
        const memeArray = memesData.data.memes
        let num = Math.floor(Math.random() * memeArray.length);
        current_meme(const url = memeArray[num].url)
        console.log(url)
    }

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

            <div>
                <img className="meme--image" src="${Image}" alt="meme" />
            </div>
        </main>
    )
}