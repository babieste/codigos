convertToCSV = (data) => {
    let lineDelimiter = '\n', columnDelimiter = ';';
    let keys, values, result = '';

    if(!data){
        return null;
    }

    keys = Object.keys(data);

    result += keys.join(columnDelimiter);
    result += lineDelimiter;

    values = Object.values(data);
    
    result += values.join(lineDelimiter);
    result += columnDelimiter;
    
    console.log(result);
}