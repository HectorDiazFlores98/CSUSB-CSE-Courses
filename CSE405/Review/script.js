function HideOrShow() {
    
    var div = document.getElementById('object');
    
    if (div.style.visibility === 'hidden') 
    {
        div.style.visibility = 'visible';
    } 
    else 
    {
        div.style.visibility = 'hidden';
    }
}
