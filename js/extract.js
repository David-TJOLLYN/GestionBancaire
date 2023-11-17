function extractNames(listOfObjects) {
    var names = [];
    for (var i = 0; i < listOfObjects.length; i++) {
        names.push(listOfObjects[i].name);
    }
    return names;
}

function getAccount(accounts, name){
    for(var i=0; i<accounts.length; i++){
        if(accounts[i].name == name) return accounts[i]
    }
}

function generateDateList(start_date,end_date){

    //Convert chain date in objects
    var startDate = new Date(start_date);
    var endDate = new Date(end_date);

    //Check if start date precede end date
    if(startDate > endDate){
        console.error("Start date must be prior end date.");
        return [];
    }

    var dates = [];
    var currentDate = new Date(startDate);

    // Loop until current date is lower or equal than end date
    while(currentDate <= endDate){

        // Add date in the fomrat YYYY-MM-DD in the list
        dates.push(currentDate.toISOString().slice(0,10));

        // Go to next mounth
        currentDate.setMonth(currentDate.getMonth()+1);
    }

    return dates;
}
