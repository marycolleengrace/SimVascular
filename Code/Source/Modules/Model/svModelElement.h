#ifndef SVMODELELEMENT_H
#define SVMODELELEMENT_H

#include <svModelExports.h>

#include <mitkDataNode.h>

#include <vtkPolyData.h>
#include <vtkSmartPointer.h>

class SVMODEL_EXPORT svModelElement
{

public:

    struct svFace
    {
        int id;
        std::string name;
        vtkSmartPointer<vtkPolyData> vpd;

        bool selected;

        float opacity;
        bool visible;
        float color[3];

        bool isWall; // wall or cap

        svFace()
            : id(0)
            , name("")
            , vpd(NULL)
            , selected(false)
            , opacity(1.0f)
            , visible(true)
            , isWall(true)
        {
            color[0]=1.0f;
            color[1]=1.0f;
            color[2]=1.0f;
        }

    };

    svModelElement();

    svModelElement(const svModelElement &other);

    virtual ~svModelElement();

    virtual svModelElement* Clone();

    std::string GetType() const;

    void SetType(std::string type);

    std::vector<std::string> GetSegNames() const;

    void SetSegNames(std::vector<std::string> segNames);

    bool HasSeg(std::string segName);

    std::vector<svFace*> GetFaces() const;

    void SetFaces(std::vector<svFace*> faces);

    svFace* GetFace(int id) const;

    int GetFaceIndex(int id) const;

    std::string GetFaceName(int id) const;

    void SetFaceName(std::string name, int id); //Todo: make virtual

    vtkSmartPointer<vtkPolyData> GetWholeVtkPolyData() const;

    void SetWholeVtkPolyData(vtkSmartPointer<vtkPolyData> wvpd);

    virtual vtkSmartPointer<vtkPolyData> CreateFaceVtkPolyData(int id) {}

//    int GetSelectedFaceIndex();

    void SetSelectedFaceIndex(int idx);

    void ClearFaceSelection();

    void CalculateBoundingBox(double *bounds);

  protected:

    std::string m_Type;

    std::vector<std::string> m_SegNames;

    std::vector<svFace*> m_Faces;

    vtkSmartPointer<vtkPolyData> m_WholeVtkPolyData;

  };


#endif // SVMODELELEMENT_H
