import React from 'react';


export default function Meme () {
    return(
        <main className="meme">
            <form className="form">
                <input className="meme--input" type="text" placeholder="Top text" />
                <input className="meme--input" type="text" placeholder="Bottom text" />
                <button className="meme--button"> Get a new meme image </button>
            </form>
        </main>
    )
}