Public Class Student
    Dim rollSt As Integer
    Dim nameStudent As String
    Dim deptName As String
    Dim deptCo As String

    Public Sub New(roll As String, nm As String, dep As String, dc As String)
        rollSt = roll
        nameStudent = nm
        deptName = dep
        deptCo = dc
    End Sub

    Public Function getRoll() As String
        Return rollSt
    End Function

    Public Function getName() As String
        Return nameStudent
    End Function

    Public Function getDept() As String
        Return deptName
    End Function

    Public Function getDcode() As String
        Return deptCo
    End Function

    Public Sub setName(n As String)
        nameStudent = n
    End Sub



End Class
