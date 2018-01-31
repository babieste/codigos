angular.module('starter.controllers', [])

.controller('DashCtrl', function($scope) {
  $scope.adicionar = (numero1, numero2) => {
    $scope.resultado = numero1 + numero2;
    // console.log($scope.resultado);
  }

  $scope.subtrair = (numero1, numero2) => {
    $scope.resultado = numero1 - numero2;
  }

  $scope.multiplicar = (numero1, numero2) => {
    $scope.resultado = numero1 * numero2;
  }

  $scope.dividir = (numero1, numero2) => {
    if(numero2 == 0){
      $scope.resultado = 'Divisão por zero!';
    } else {
      $scope.resultado = numero1 / numero2;
    }
  }


})

.controller('ChatsCtrl', function($scope, Chats) {
  // With the new view caching in Ionic, Controllers are only called
  // when they are recreated or on app start, instead of every page change.
  // To listen for when this page is active (for example, to refresh data),
  // listen for the $ionicView.enter event:
  //
  //$scope.$on('$ionicView.enter', function(e) {
  //});

  $scope.chats = Chats.all();
  $scope.remove = function(chat) {
    Chats.remove(chat);
  };
})

.controller('ChatDetailCtrl', function($scope, $stateParams, Chats) {
  $scope.chat = Chats.get($stateParams.chatId);
})

.controller('AccountCtrl', function($scope) {
  $scope.cabras = [{"nome": "Margarida"}, {"nome": "Francine"}, {"nome": "Roberto Carlos"}];

  $scope.adicionarCabra = (nome) => {
    $scope.cabras.push({"nome": nome});
  }
});
