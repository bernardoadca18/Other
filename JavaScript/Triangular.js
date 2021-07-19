//  0, 1, 3, 6, 10, 15, 21
//  0, 1, 2, 3, 04, 05, 06

/*
    1 = 1
    1 + 2 = 3
    1 + 2 + 3 = 6
    1 + 2 + 3 + 4 = 10
    1 + 2 + 3 + 4 + 5 = 15
    1 + 2 + 3 + 4 + 5 + 6 = 21
*/

function triangularNumNonRecursive(index)
{
    if(index <= 1)
    {
        return index;
    }

    var sum = 0;

    for(var i = 0; i <= index; i++)
    {
        sum += i;
    }
    return sum;
}

console.log("Resultado (Função não recursiva): " + triangularNumNonRecursive(8));

function triangularNumRecursive(index)
{
    if(index <= 1)
    {
        return index;
    }
    else
    {
        return index + triangularNumRecursive(index - 1);
    }
}

console.log("Resultado (Função recursiva): " + triangularNumRecursive(8));