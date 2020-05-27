**--------------------COMO USAR GIT--------------------**

**Inicar pasta como repositório**

git init

**Baixar o projeto**

git clone https://github.com/annajuliapg/Arvores.git

**Subir arquivos**

git add .

git commit -m " qualquer mensagem "

git push origin <branch>
  

**Atualizar pasta no computador**

git pull

git commit -m " qualquer mensagem "


**Criar novo branch**

git checkout -b <branch>


**Merge - Tem que estar sem alteração local**

git checkout master

git pull

git checkout <branch>
  
git merge master

e depois abrir um pull request e mergear
