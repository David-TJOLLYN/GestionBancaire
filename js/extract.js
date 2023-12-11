function extractNames(listOfObjects) {
    var names = [];
    for (var i = 0; i < listOfObjects.length; i++) {
        names.push(listOfObjects[i].name);
    }
    return names;
}

function getAccount(accounts, name){
    for(var i=0; i<accounts.length; i++){
        if(accounts[i].name === name) return accounts[i]
    }
}

function removeAccount(accounts, name){
    var list=[];
    for(var i=0; i<accounts.length; i++){
        if(accounts[i].name !== name) list.push(accounts[i])
    }
    return list;
}

function generateDateList(start_date, end_date) {
    // Convert chain date in objects
    var startDate = new Date(start_date);
    var endDate = new Date(end_date);

    // Check if start date precedes end date
    if (startDate > endDate) {
        console.error("Start date must be prior to end date.");
        return [];
    }

    var dates = [];
    var currentDate = new Date(startDate);

    // Loop until current date is lower or equal to end date
    while (currentDate <= endDate) {
        // Add date in the format MM/YY to the list
        var month = String(currentDate.getMonth() + 1).padStart(2, '0');
        var year = String(currentDate.getFullYear()).slice(2);
        dates.push(`${month}/${year}`);

        // Go to the next month
        currentDate.setMonth(currentDate.getMonth() + 1);
    }

    return dates;
}


function formatDate(inputDate) {
    var txt = inputDate.split("-");
    var currentDate = new Date();
    var currentYear = currentDate.getFullYear();

    if (parseInt(txt[0]) !== currentYear) {
        // If the year is the current year, format as dd/mm/yyyy
        return txt[2] + "/" + txt[1] + "/" + txt[0];
    } else {
        // If the year is not the current year, format as dd/mm
        return txt[2] + "/" + txt[1];
    }
}

function getTableFromLastTransactions(accounts,name, nbr){
    var account = getAccount(accounts, name);
    var transactions = account.getLastTransactions(nbr);
    var array = [];

    for(var i=0; i<transactions.length;i++){
        var date     = formatDate(transactions[i].date);
        var amount   = transactions[i].amount;
        var category = transactions[i].category;
        var details  = transactions[i].details;

        array.push({"date" : date, "amount":amount, "category":category, "details":details});
    }

    return array;
}

function addTransaction(account,date,amount,category,details){
    account.addTransaction(date,amount,category,details);
}

function date(){
    var currentDate = new Date();
    var date = currentDate.toISOString().split('T')[0];
    return date
}
