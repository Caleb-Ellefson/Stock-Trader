
    window.addEventListener('scroll', function (){
        const parallax = document.querySelector('.parallax');
        let scrollPosition = window.pageYOffset;

        console.log(scrollPosition);
        parallax.style.transform = 'translateY(' + scrollPosition * .5 + 'px')
    })
