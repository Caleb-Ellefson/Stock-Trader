import React from 'react';
import memesData from "../memesData.js";



const memesArray = memesData.data.memes
const randomNumber = Math.floor(Math.random() * memesArray.length)

export default function Meme () {
    const [Image, current_meme] = React.useState(memesArray[randomNumber].url)

    function generate() {
        const memesArray = memesData.data.memes
        const randomNumber = Math.floor(Math.random() * memesArray.length)
        current_meme(old => old = (memesArray[randomNumber].url))
        console.log(current_meme)

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
                <img className="meme--image" src={Image} alt="meme" />
            </div>
        </main>
    )
}