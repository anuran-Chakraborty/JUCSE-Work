Imports School.StudentList
Public Class FormAllRec
    Dim startIndex As Integer
    Dim endIndex As Integer

    Private Sub prev_btn_Click(sender As Object, e As EventArgs) Handles prev_btn.Click
        endIndex = startIndex - 1
        startIndex = endIndex - 4
        If (startIndex = 0) Then
            ' Disable prev
            prev_btn.Enabled = False
        Else
            prev_btn.Enabled = True
        End If

        If (endIndex >= stList.Count()) Then
            'Disable next
            next_btn.Enabled = False
        Else
            next_btn.Enabled = True
        End If

        populateTable()

    End Sub

    Private Sub next_btn_Click(sender As Object, e As EventArgs) Handles next_btn.Click
        startIndex = endIndex + 1
        endIndex = startIndex + 4

        If (startIndex = 0) Then
            ' Disable prev
            prev_btn.Enabled = False
        Else
            prev_btn.Enabled = True
        End If

        If (endIndex >= stList.Count()) Then
            'Disable next
            next_btn.Enabled = False
        Else
            next_btn.Enabled = True
        End If
        populateTable()
    End Sub

    Private Sub FormAllRec_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        startIndex = 0
        endIndex = 4
        prev_btn.Enabled = False

        If (endIndex >= stList.Count()) Then
            endIndex = stList.Count() - 1
            next_btn.Enabled = False
        End If
        ' Call function to populate grid view
        populateTable()
    End Sub

    Private Sub populateTable()
        records.Rows.Clear()
        For i = startIndex To Math.Min(stList.Count() - 1, endIndex)
            records.Rows.Add({stList(i).getRoll(), stList(i).getName(), stList(i).getDept(), stList(i).getDcode()})
        Next
    End Sub
End Class