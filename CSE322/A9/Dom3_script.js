function example1Function(){
    document.getElementById('example1Photo').src='https://78.media.tumblr.com/c2170b0087b4af2dbc733757bcbdef0e/tumblr_inline_ouw1egW0OG1tzhl5u_1280.gif';
    var button= document.getElementById('example1Button');
    
    function alertWindow() {
        alert('This is an example of using addEventListener as a function');
        
    }
    button.addEventListener('click', alertWindow() , false);
}

function example2Function(){
    var img = document.getElementById('stopsign');
    var clickFunc = function() {
    alert('This message was created, and will no longer pop up if the photo is clicked on again');
    img.removeEventListener('click', clickFunc, false);
    }; 
    img.addEventListener('click', clickFunc, false);
}

function example3Function(){
    var func = function(e) {
      if (e.target.src) {
        e.target.src = 'http://www.stopsignsandmore.com/images/Product/medium/435.gif';
      }
    };
    document.getElementById('stop_table').addEventListener('mouseover', func, false);

}
function example4Function(){
var func = function(e) {
  if (e.charCode < 48 || e.charCode > 57) {
    e.preventDefault();
  }
};
document.getElementById('phoneNumber').addEventListener('keypress', func, false);
}