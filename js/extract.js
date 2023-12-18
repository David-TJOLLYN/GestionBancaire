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
    return txt[2] + "/" + txt[1] + "/" + txt[0];
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

function maxAbsoluteValue(arr) {
  if (!Array.isArray(arr) || arr.length === 0) {
    return null; // Return null for an empty or non-array input
  }

  // Use Math.abs to get the absolute values, then find the maximum
  const maxAbsolute = Math.max(...arr.map(num => Math.abs(num)));

  return maxAbsolute;
}





// Assuming inputDate is in the format "MM/YYYY"

function extractMonthToLongString(inputDate) {
    var monthNames =["Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"];
    return monthNames[parseInt(inputDate.split('/')[0])-1];
}

function extractYear(inputDate){
    return inputDate.split('/')[1]
}

function extractMonthToShortString(inputDate) {
    var monthNames =["jan.", "fév.", "mars", "avr.", "mai", "juin", "juil.", "août", "sept.", "oct.", "nov.", "dec."];
    return monthNames[parseInt(inputDate.split('/')[0])-1];
}

function format2db(inputDate){
    var date = inputDate.split('/')
    return "20"+date[1]+"-"+date[0]+"-01";
}
