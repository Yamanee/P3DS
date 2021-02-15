#include <Maths/Vector.h>

#include <QGuiApplication>
#include <QWindow>

int main(int argc, char** argv)
{
  QGuiApplication app(argc, argv);

  peds::Vector myVector;
  myVector.hello();

  QWindow window(static_cast<QWindow*>(nullptr));
  window.setTitle("Hellow world");
  window.show();

  return app.exec();
}
