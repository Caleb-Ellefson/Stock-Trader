
    window.addEventListener('scroll', function (scroll){
        const parallax = document.querySelector('.parallax');
        let scrollPosition = window.pageYOffset;

        console.log(scrollPosition);
        parallax.style.transform = 'translateY(' + scrollPosition * .5 + 'px)';
    });
