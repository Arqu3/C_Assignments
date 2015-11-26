#include "Container.h"
#include "ShapeTool.h"

using namespace std;

int main()
{
	Container container;

	container.add(ShapeTool::createSquare(2, 3));
	container.add(ShapeTool::createCircle(3));
	container.add(ShapeTool::createTriangle(2, 10));

	container.output();

	container.clear();

	system("Pause");

	return 0;
}