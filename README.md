# GestionBancaire
Application permettant de suivre les transaction sur son compte.

darkBlue : #3C6888
lightBlue: #98D7E5

Pour modifier le fichier de traduction :
 -> text à traduire dans qsTr()
 -> executer $lupdate qml.pro
 -> ouvrir le fichier de traduction language/bankhandler_en.ts dans Linguist (Qt version/bin)
 -> effectuer les traduction
 -> executer $lrelease qml.pro
 -> copier le fichier language/bankhandler_en.qm dans le build et dans le dossier root (qml)
 