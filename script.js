const inputs = document.getElementsByClassName('take-text');
const button = document.getElementById('compare');
const lists = document.getElementsByTagName('ul');
button.addEventListener('click', () => {
    let getLength = () => {
        if(inputs[0].value.length > inputs[1].value.length)
            return inputs[0].value.length
        else
            return inputs[1].value.length
    };
    let len = getLength();
    // Add list items with content
    for(a = 0; a < inputs.length; a++){
        clearList(lists[a]);
        for(i = 0; i < len; i++){
            let item = document.createElement('li');
            let textNode = document.createTextNode(inputs[a].value[i]);
            item.appendChild(textNode);
            lists[a].appendChild(item);
        }
    }
    // Generate array with lists items
    let listItems = [];
    for(a = 0; a < inputs.length; a++){
        listItems.push(lists[a].getElementsByTagName('li'));
    }
    // If chars match make them green else red
    let areStringsSame = true;
    for(i = 0; i < len; i++){
        if(listItems[0][i].innerHTML === listItems[1][i].innerHTML){
            console.log(`${listItems[0][i].innerHTML} , ${listItems[1][i].innerHTML}`)
            listItems[1][i].classList.add('match');
        }else{
            areStringsSame=false;
            listItems[1][i].classList.add('unmatch');
        }
    }
    let p = document.querySelector('p');
    let msg;
    if(areStringsSame)
        msg = "Strings are the same";
    else
        msg = "Strings are diffrent";
    p.innerHTML = msg;
})
// Delete content of list before use
let clearList = (ulist) => {
    let len = ulist.getElementsByTagName('li').length;
    for(i = len; i > 0; i--){
        ulist.removeChild(ulist.firstElementChild);
    }
}