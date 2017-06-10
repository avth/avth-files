/*
 *	@Author		:	Amsavarthini Easwaran
 *	@Started	:	2017-03-22
 */

class Conversion {
	public:
		Conversion();
		~Conversion();
		virtual void conversionInfo();
};

Conversion::Conversion() {
}
Conversion::~Conversion() {
}
void Conversion::conversionInfo() {
	cout<<"\n Conversions Implemented:	Decimal-Binary\n";
}
