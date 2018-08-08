#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std; 

inline void error(const string &s) {
	throw runtime_error(s);
}

class Token {
	public:
		char kind;
		double value;
};

class Token_stream {
	public:
		Token_stream();
		Token get();
		void putback(Token t);
	private:
		bool full {false};
		Token buffer; //where keep token put back using putback
};

Token_stream::Token_stream() {}

void Token_stream::putback(Token t) {
	if(full) error("putback() into a full buffer");
	buffer = t;
	full = true;
}

Token Token_stream::get() {
	if(full) {
		full = false;
		return buffer;
	}
	
	char ch;
	cin>>ch;
		
	switch(ch) {
		case ';': //for print
		case 'q': //for quit
		case '(': case ')': case '+': case '-': case '*': case '/':
			return Token{ch}; //let each character represent itself
		
		//number literal starts with digit or .
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9': { 
			cin.putback(ch); //put digit back into input stream
			double val;
			cin >> val;
			return Token{'8', val}; //let 8 represnt a number
		}
				
		default:
			error("bad token");
	}
}

Token_stream ts;
double expression();

double primary() {
	Token t = ts.get();
	switch(t.kind) {
		case '(': {
			double d = expression();
			t = ts.get();
			if(t.kind != ')') {
				error("')' expected");
			}
			return d;
		}
		
		case '8':
			return t.value;
		
		default:
			error("primary expected");
	}
}

double term() {
	double left = primary();
	Token t = ts.get();
	while(true) {
		switch(t.kind) {
			case '*':
				left *= primary();
				t = ts.get();
				break;	
			
			case '/': {
				double d = primary();
				if (d==0) error("divide by 0");
				left /= d;
				t = ts.get();
				break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression() {
	double left = term();
	Token t = ts.get();
	while(true) {
		switch(t.kind) {
			case '+':
				left += term();
				t = ts.get();
				break;
			
			case '-':
				left -= term();
				t = ts.get();
				break;
			
			default:
				ts.putback(t);
				return left;
		}
	}
}

int main() {
	try {
		double val = 0;
		while(cin) {
			Token t = ts.get();
			if(t.kind == 'q') {
				break;
			}
			if(t.kind == ';') {
				cout << "=" << val << endl;
			}
			else {
				ts.putback(t);
			}
			val = expression();
		}
	}
	catch(exception &e) {
		cerr << e.what() << endl;
		return 1;	
	}
	catch(...) {
		cerr << "exception\n";
		return 2;
	}
}

//old main
/*

int main() {
	cout << "Please enter expression: \n";
	cout << "Add x to end expression: ";
	
	int lval = 0;
	int rval;

	Token t1 {'+'};
	Token t2 {'8', 11.5};
	
	cin >> lval; //read leftmost operand
	
	if(!cin) {
		error("no first operand");
	}

	for(char op; cin >> op; ) {
			if(op != 'x') {
				cin >> rval;
			}
		
			if(!cin) {
				error("no second operand");
			}

			switch(op) {
				case '+':
					lval += rval;
					break;
				
				case '-':
					lval -= rval;
					break;
				
				case '*':
					lval *= rval;
					break;
				
				case '/':
					lval /= rval;
					break;
			
				default:	//not another operator
					cout << "Result: " << lval << endl;
					return 0;
			}
	}
	
	error("bad expression");	
}

*/
