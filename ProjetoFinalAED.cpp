#include <bits/stdc++.h>
using namespace std;

struct eProduct{ //struct para um produto
    string nomeP;
    int IDproduto;
    float preco;
    int QTD;
    struct eProduct *proximo;
    struct eProduct *anterior;
};

struct LISTAP{ //struct para uma lista com produtos
    eProduct *inicio,*fim;
};

struct CARGO{ //struct para o cargo do funcionario
  string nameC;
  int chave;
};

struct CONTA{ //struct para a conta do funcionario e cliente
	string user,password;
};

class empresa{
protected:
	int totalFuncionarios;
	int totalClientes;
	int totalJogos;
public:
	empresa(){ //construtor da empresa
		totalFuncionarios = 0;
		totalClientes = 0;
		totalJogos = 0;
	}
	int getFunc(){ //retorna o total de funcionarios na empresa
		return totalFuncionarios;
	}
	int getClientes(){//retorna o total de clientes da empresa
		return totalClientes;
	}	
	int getTJogos(){ //retorna o total de jogos na empresa
		return totalJogos;
	}
	void changeFunc(bool opt){ // adiciona ou subtrai do total de funcionarios
		switch(opt){
			case 0:
				totalFuncionarios++;
				break;
			case 1:
				totalFuncionarios--;
				break;
		}

	}
	void changeClientes(bool opt){ //adiciona ou subtrai do total de clientes
		switch(opt){
			case 0:
				totalClientes++;
				break;
			case 1:
				totalClientes--;
				break;
		}
	}
	void changeJogos(bool opt){ //adiciona ou subtrai do total de Jogos
		switch(opt){
			case 0:
				totalJogos++;
				break;
			case 1:
				totalJogos--;
				break;
		}
	}
};
class produto: public empresa{
protected:
    LISTAP tlista; //lista de produtos da empresa
public:
	
	produto(){ //construtor da classe
		tlista.inicio = NULL;
		tlista.fim = NULL;
	}
	
    void setProduct(){ //adiciona um produto na lista de produtos da empresa(feita por um funcionario)
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
		if(tlista.inicio = NULL){//se não tiver produto no catálogo
			tlista.inicio = newProduct;//o produto entra como o primeiro
			tlista.fim = newProduct;//o produto entra também como ultimo
		}else{// se não, é adicionada no fim do catálogo
			newProduct->anterior = tlista.fim;
			tlista.fim->proximo = newProduct;
			tlista.fim = newProduct;
		}
    }
    
	void catalogoProduto(){ //apresenta o catálogo de produtos da empresa
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
	bool existe(int IDproduto){ // verifica se existe o produto no catálogo
		eProduct  *auxiliar;
		auxiliar = new eProduct;
		auxiliar = tlista.inicio;
		while(auxiliar != NULL){//percorre o catálogo
			if(auxiliar->IDproduto == IDproduto){
				return true;
			}
			auxiliar = auxiliar->proximo;
		}	
		return false;	
	}
	
	string getNomeP(int IDproduto){//retorna o nome do produto através da ID dele
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
	
	int getPrecoP(int IDproduto){//retorna o preço do produtoo ''
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
	
	virtual ~produto(){//destrutor da classe
		delete tlista.inicio;
		delete tlista.fim;
	}

};

class cliente: public produto{
protected:
	char cpf[12]; //respectivo cpf
	CONTA *contaCliente;  //conta do cliente
	LISTAP *listaDocliente; //lista no nome do cliente
	string nomeC; //nome do cliente
public:
   cliente() { //construtor da classe
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
        changeClientes(0); //soma no total de clientes registrados na empresa
        cout << "Operacao executada com sucesso.\n" << endl;
	}
	
	void carrinhoCliente(){
		int option;
		bool flag; //verificador para esvaziar o carrinho
		LISTAP *carrinho;
		eProduct *newProd,*aux,*aux2; //adicionar novo produto /auxiliar para percorrer a lista/ auxiliar para esvaziar o carrinho
		newProd = new eProduct;
		aux = new eProduct;
		catalogoProduto();
		cout << "0)Finalizar compra" << endl;
		cout << "1)Colocar produtos no carrinho" << endl;
		cout << "2)Remover produto do carrinho" << endl;
		cout << "3)Esvaziar carrinho" << endl;
		cin >> option;
		while(option != 0){
			switch(option){	
				case 1://adiciona um produto no carrinho
					cout << "Informe a ID do produto: " << endl;
					cin >> newProd->IDproduto; //lê a ID
					if(!existe(newProd->IDproduto)){ //verifica se a ID existe no catálogo
						cout << "ID do produto não está presente no catálogo!" << endl;
						break;
					}
					cout << "Informe a quantidade desse produto: " << endl;					
					do{
						cin >> newProd->QTD;
						if(newProd->QTD <= 0){
							cout << "Quantidade inválida, informe novamente:";
						}
						cout << "\n";
					}while(newProd->QTD <= 0);//verifica se a quantidade é um valor correto
					newProd->nomeP = getNomeP(newProd->IDproduto); //associa o nome pela ID do produto do catálogo
					newProd->preco = getPrecoP(newProd->IDproduto);//associa o preço ''
					newProd->proximo = NULL;
					newProd->anterior = NULL;
					if(carrinho->inicio == NULL ){ //se não tiver itens no carrinho
						carrinho->inicio = newProd; //inicio vira o produto
						carrinho->fim = newProd; // fim vira o produto
					}else{// se já tiver produtos no carrinho, acrescenta no fim
						newProd->anterior = carrinho->fim;
						carrinho->fim->proximo = newProd;
						carrinho->fim = newProd;
					}
					break;
				case 2: //Remover produto do carrinho
					system("cls");
					int remove;
					aux = carrinho->inicio;
					cout << "~Produtos no carrinho~" << endl;
					while(aux != NULL){ //apressenta os produtos que já estão no carrinho
						cout << aux->IDproduto << "	|	" << aux->nomeP << "	|	" << aux->QTD << "	|	" <<(aux->preco * aux->QTD);
						aux = aux->proximo;
					}
					cout << "Informe a ID do produto a ser removido: ";
					cin >> remove; // le a ID do produto
					aux = carrinho->inicio;
					while(aux != NULL){
						if(carrinho->inicio->proximo == NULL && aux->IDproduto == remove){ //se só tiver um elemento no carrinho e a pessoa digitou a ID correta
							carrinho->inicio = NULL;
							carrinho->fim = NULL;
							cout << "Produto removido com sucesso!" << endl;
							break;
						}
						if(aux->IDproduto == remove){// se a ID for correta
							if(aux == carrinho->inicio){ // se a ID for do primeiro item do carrinho
								carrinho->inicio = aux->proximo;
								aux->proximo->anterior = NULL;
								free(aux);
								cout << "Produto removido com sucesso!" << endl;
								break;
							}else if(aux == carrinho->fim){//se a ID for do ultimo item do carrinho
								carrinho->fim = aux->anterior;
								aux->anterior->proximo = NULL;
								free(aux);
								cout << "Produto removido com sucesso!" << endl;
								break;
							}else{ //se a ID for de um produto no meio do carrinho
								aux->anterior->proximo = aux->proximo;
								aux->proximo->anterior = aux->anterior;
								free(aux);
								cout << "Produto removido com sucesso!" << endl;
								break;
							}
						}else{
							aux = aux->proximo;
						}
					}
					break;
				case 3: //esvazia o carrinho
					system("cls");
					cout << "Deseja mesmo cancelar a compra? (1) Sim (0) Não" << endl;
					cin >> flag;
					if(flag && carrinho->inicio != NULL){
						aux = carrinho->inicio;
						while(aux != NULL){
							aux2 = aux;
							aux = aux->proximo;
							free(aux2);
						}
						carrinho->inicio = NULL;
						carrinho->fim = NULL;
						cout << "Carrinho esvaziado!" << endl;
					}
					break;
			}
			catalogoProduto();
			cout << "0)Finalizar compra" << endl;
			cout << "1)Colocar produtos no carrinho" << endl;
			cout << "2)Remover produto do carrinho" << endl;
			cout << "3)Esvaziar carrinho" << endl;
			cin >> option;
		}
		aux2 = carrinho->inicio;
		while(aux2 != NULL){
			for(int cont = 0;cont < aux2->QTD;cont++){
				changeJogos(1); //reduz a quantidade total de jogos disponiveis na empresa
			}
			aux2 = aux2->proximo;
		}
		aux2 = carrinho->inicio;
		if(listaDocliente->inicio == NULL && carrinho->inicio != NULL){//se a lista não tiver produto e o carrinho tiver produtos
			listaDocliente = carrinho; //a lista recebe os produtos do carrinho
		}else if(listaDocliente->inicio != NULL && carrinho->inicio != NULL){ // se a lista ja tiver produto
			while(aux2 != NULL){ // coloca os itens do carrinho no fim da lista de produtos locados pelo cliente
				listaDocliente->fim->proximo = aux2;
				aux2->anterior = listaDocliente->fim;
				listaDocliente->fim = aux2;
				aux2 = aux2->proximo;
			}
		}		
	}
	
	~cliente(){ //destrutor da classe
	    delete[] contaCliente;
	    delete[] listaDocliente;
	}
};

class funcionario: public cliente{
protected:
    CARGO *IDcargo; //ID do respectivo cargo do funcionario
	int IDfuncionario; //ID do funcionario
	CONTA *contaFuncionario;//conta do funcionario
	string nomeF;//nome do funcionario
public:
	funcionario () {//construtor da classe
	        IDcargo = NULL;
			IDfuncionario = 0;
			nomeF = " ";
			contaFuncionario = NULL;
	}
	~funcionario(){ //destrutor da classe
	    delete[] IDcargo;
	    delete[] contaFuncionario;
	}
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    cout << "penes" << endl;
	return 0;
}
