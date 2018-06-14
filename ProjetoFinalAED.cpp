#include <bits/stdc++.h>
using namespace std;

struct eProduct{
    string nomeP;
    int IDproduto;
    float preco;
    int QTD;
    struct eProduct *proximo;
    struct eProduct *anterior;
};

struct LISTAP{
    eProduct *inicio,*fim;
};

struct CARGO{
  string nameC;
  int chave;
};

struct CONTA{
	string user,password;
};

class empresa{
protected:
	int totalFuncionarios;
	int totalClientes;
	int totalJogos;
public:
	empresa(){
		totalFuncionarios = 0;
		totalClientes = 0;
		totalJogos = 0;
	}
	int getFunc(){
		return totalFuncionarios;
	}
	int getClientes(){
		return totalClientes;
	}	
	int getTJogos(){
		return totalJogos;
	}
	void changeFunc(bool opt){
		switch(opt){
			case 0:
				totalFuncionarios++;
				break;
			case 1:
				totalFuncionarios--;
				break;
		}

	}
	void changeClientes(bool opt){
		switch(opt){
			case 0:
				totalClientes++;
				break;
			case 1:
				totalClientes--;
				break;
		}
	}
	void changeJogos(bool opt){
		switch(opt){
			case 0:
				totalJogos++;
				break;
			case 1:
				totalJogos--;
				break;
		}
	}
	void catalogo(){
	    cout << "" << endl;
	}
};
class produto: public empresa{
protected:
    LISTAP tlista;      
public:
	
	produto(){
		tlista.inicio = NULL;
		tlista.fim = NULL;
	}
	
    void setProduct(){
    	eProduct *newProduct;
    	newProduct = new eProduct;
    	cout << "Informe o nome do produto:\n" << endl;
		cin >> newProduct->nomeP;
		cout << "Informe a ID do produto:\n" << endl;
		cin >> newProduct->IDproduto;
		cout << "Informe o preco do produto:\n" << endl;
		cin >> newProduct->preco;
		cout << "Informe a quantidade do produto em estoque:\n" << endl;     
		cin >> newProduct->QTD;
		for(int i=0;i<newProduct->QTD;i++){
			changeJogos(0);
		}
		newProduct->proximo = NULL;
		newProduct->anterior = NULL;
		if(tlista.inicio = NULL){
			tlista.inicio = newProduct;
			tlista.fim = newProduct;
		}else{
			newProduct->anterior = tlista.fim;
			tlista.fim->proximo = newProduct;
			tlista.fim = newProduct;
		}
    }
    
	void catalogoProduto(){
	    eProduct *aux;
	    aux = new eProduct;
	    aux = tlista.inicio;
	    cout << "Catalogo de Produtos" << endl;
	    cout << "Codigo" << "	|	" <<"Nome" << "	|	" << "Preço" << "	|	" << "Quantidade";
	    while(aux != NULL){
	        cout << aux -> IDproduto << "	|	" << aux -> nomeP << "	|	" << aux -> preco << "	|	" << aux -> QTD << endl;
	        aux = aux -> proximo;
	    }
	}
	bool existe(int IDproduto){
		eProduct  *auxiliar;
		auxiliar = new eProduct;
		auxiliar = tlista.inicio;
		while(auxiliar != NULL){
			if(auxiliar->IDproduto == IDproduto){
				return true;
			}
			auxiliar = auxiliar->proximo;
		}	
		return false;	
	}
	
	string getNomeP(int IDproduto){
		eProduct  *auxiliar;
		auxiliar = new eProduct;
		auxiliar = tlista.inicio;
		while(auxiliar != NULL){
			if(auxiliar->IDproduto == IDproduto){
				return auxiliar->nomeP;
			}
			auxiliar = auxiliar->proximo;
		}
	}
	
	int getPrecoP(int IDproduto){
		eProduct  *auxiliar;
		auxiliar = new eProduct;
		auxiliar = tlista.inicio;
		while(auxiliar != NULL){
			if(auxiliar->IDproduto == IDproduto){
				return auxiliar->preco;
			}
			auxiliar = auxiliar->proximo;
		}		
	}
	
	virtual ~produto(){
		delete tlista.inicio;
		delete tlista.fim;
	}

};

class cliente: public produto{
protected:
	char cpf[12];
	CONTA *contaCliente;
	LISTAP *listaDocliente;
	string nomeC;
public:
   cliente() {
			nomeC = "";
			listaDocliente = NULL;
			contaCliente = NULL;
			for (int i = 0; i < 12; i++) 
				cpf [i] = 0;
	}
	
	void registerClient(){
	    cout << "Informe o nome completo:\n" << endl;
	    getchar(); 
	    getline(cin,nomeC);
	    cout << "Informe o CPF:\n" << endl;
	    getchar();
		fgets(cpf,12,stdin);
		cout << "Informe o nome de usuário:\n" << endl;
        cin >> contaCliente->user;
        cout << "Informe a senha (no mínimo 6 caracteres):\n" << endl;
        do{
            cin >> contaCliente->password;
        }while((contaCliente->password.size()) <= 6);
        cout << "Operacao executada com sucesso.\n" << endl;
	}
	
	void carrinhoCliente(){
		int option;
		LISTAP *carrinho;
		eProduct *newProd;
		newProd = new eProduct;
		catalogoProduto();
		cout << "0)Finalizar compra" << endl;
		cout << "1)Colocar produtos no carrinho" << endl;
		cout << "2)Remover produto do carrinho" << endl;
		cout << "3)Cancelar compra" << endl;
		cin >> option;
		while(option != 0){
			switch(option){
				case 1:
					cout << "Informe a ID do produto: " << endl;
					cin >> newProd->IDproduto;
					if(!existe(newProd->IDproduto)){
						cout << "ID do produto não está presente no catálogo!" << endl;
						cout << "Informe novamente!" << endl;
						break;
					}
					cout << "Informe a quantidade desse produto: " << endl;					
					do{
						cin >> newProd->QTD;
						if(newProd->QTD <= 0){
							cout << "Quantidade inválida, informe novamente:";
						}
						cout << "\n";
					}while(newProd->QTD <= 0);
					newProd->nomeP = getNomeP(newProd->IDproduto);
					newProd->preco = getPrecoP(newProd->IDproduto);
					newProd->proximo = NULL;
					newProd->anterior = NULL;
					if(carrinho->inicio == NULL ){
						carrinho->inicio = newProd;
						carrinho->fim = newProd;
					}else{
						newProd->anterior = carrinho->fim;
						carrinho->fim->proximo = newProd;
						carrinho->fim = newProd;
					}
					break;
				case 2:
					break;
			}
					
		}
	}
	
	~cliente(){
	    delete[] contaCliente;
	    delete[] listaDocliente;
	}
};

class funcionario: public cliente{
protected:
    CARGO *IDcargo;
	int IDfuncionario;
	CONTA *contaFuncionario;
	string nomeF;
public:
	funcionario () {
	        IDcargo = NULL;
			IDfuncionario = 0;
			nomeF = " ";
			contaFuncionario = NULL;
	}
	virtual ~funcionario(){
	    delete[] IDcargo;
	    delete[] contaFuncionario;
	}
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    cout << "penes" << endl;
	return 0;
}
