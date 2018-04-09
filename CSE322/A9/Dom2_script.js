function example1Function(){
    document.getElementById('theft').innerHTML= '<p>You shouldnt be using it in the first place</p><img src=http://images.entertainment.ie/images_content/rectangle/620x372/Screen-Shot-2016-09-10-at-175938.png>'
}

function example2Function(){
    var child = document.getElementById('child');
    child.parentNode.removeChild(child);
}

function example3Function(){
    document.getElementById('target').appendChild(document.getElementById('family').lastChild.previousSibling.previousSibling);
}

function example4Function(){
    
document.getElementById('paintingname').appendChild(document.createTextNode('Mona Lisa'));

    
}

function example5Function() {
    var paragraph = document.createElement('h1');   
    var paragraphText = document.createTextNode("This has been created using createElement and createTextNode!");
    paragraph.appendChild(paragraphText);
    
    document.getElementById('example5Span').appendChild(paragraph);
}