#ifndef SALLY_H
#define SALLY_H

class Sally {
	public:
		Sally();
		Sally(int a, int b);
		~Sally();
		void printCrap();
		void printNums();
	protected:
	private:
		int regVar;
		const int constVar;
};

#endif
