//var l = process.argv[2];

function getRandomString(length)
{
    var letters = 
    [
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
    ]

    var string = [];
    for(var i = 0; i < length; i++)
    {
        string.push(letters[Math.floor(Math.random() * letters.length)]);
    }

    return string.toString();
}

for(var l = 0; l < 5; l++)
{
    console.log(getRandomString(5));
}