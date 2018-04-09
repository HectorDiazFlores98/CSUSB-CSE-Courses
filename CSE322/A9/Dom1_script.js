function example1Function(){
    document.getElementById("SanFran").src="https://cdn.vox-cdn.com/thumbor/RVhobHgNC4xy7NSqXvVs13OdJIk=/0x0:4000x4000/1200x800/filters:focal(1680x1680:2320x2320)/cdn.vox-cdn.com/uploads/chorus_image/image/55649931/IM_Photo5.0.jpg";
    
}

function example2Function(){
    document.getElementById("coloredP").childNodes[1].style.color="red";
    document.getElementById("coloredP").childNodes[3].style.color="blue";
    document.getElementById("coloredP").childNodes[5].style.color="yellow";
}

function example3Function(){
   document.getElementById('coloredP2').firstChild.textContent="I AM the first child";
   document.getElementById('coloredP2').lastChild.textContent="It is!";
   
   
}

function example4Function(){
   document.getElementById("lastChild").previousSibling.textContent="I am now hidden!";
}

function example5Function(){
   document.getElementById("child").parentNode.nextSibling.textContent="I have changed the text by going to the parent Node";
}