var fs = require('fs');
var child_process = require('child_process');

function compileFile(f){
	return compileString(fs.readFileSync(__dirname + "/" + f + ".js", { encoding: "utf8" }));
}

function compileString(str){
	return str.replace(/^\s*#include\s+"([^"]+)"$/gmi, function(all, filename){
		return '\n' + compileFile(filename) + '\n';
	});
}

function compile(f){
	fs.writeFileSync(__dirname + "/" + f + "_out.js", compileFile(f), { encoding: "utf8" });
}

compile("client");

child_process.exec("java -jar compiler.jar -W QUIET -O SIMPLE --js_output_file production/client_out.js client_out.js", function(){	
	console.log("Done.");
})
