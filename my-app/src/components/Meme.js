import React from 'react';
import memesData from "../memesData.js";



const memesArray = memesData.data.memes
const randomNumber = Math.floor(Math.random() * memesArray.length)

export default function Meme () {
    const [meme, setMeme] = react.useState({
        topText: "",
        bottomText: "",
        randomImage:"http://i.imgflip.com/1bij.jpg"
    })

    const [allMemeImages, setMemeImages] = react.useState(memesArray)

    const [Image, current_meme] = React.useState(memesArray[randomNumber].url)

    function generate() {
        const memesArray = memesData.data.memes
        const randomNumber = Math.floor(Math.random() * memesArray.length)
        const url = memesArray[randomNumber].url
        setMeme(prevMeme => ({
            ...prevMeme,
            randomImage: url
        }))

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
                <img className="meme--image" src={meme.randomImage} alt="meme" />

        </main>
    )
}