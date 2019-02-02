Imports School.StudentList
Public Class Form1
    Private Sub addst_Click(sender As Object, e As EventArgs) Handles addst.Click
        Dim add As New FormAddStudent
        add.Show()
    End Sub

    Private Sub delst_Click(sender As Object, e As EventArgs) Handles delst.Click
        Dim del As New FormDelStudent
        del.Show()
    End Sub

    Private Sub editst_Click(sender As Object, e As EventArgs) Handles editst.Click
        Dim edit As New FormEditStudent
        edit.Show()
    End Sub

    Private Sub srchst_Click(sender As Object, e As EventArgs) Handles srchst.Click
        Dim srch As New FormSearchStudent
        srch.Show()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim all As New FormAllRec
        all.Show()
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        maxRoll = 1000000
    End Sub
End Class
